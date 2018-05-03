/* Daniel Bravo
 * 2018-04-11
 * CPSC 223C-01/02
 * Lab 10
 */

#include <ctype.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <string.h>

unsigned long MAX_STR_LEN;

gint tree_cmp_func(gconstpointer a, gconstpointer b)
{
  return strcmp(a, b);
}

GTree * count_word_freq(gchar **strs)
{
  GTree *cnts = g_tree_new(tree_cmp_func);

  int i = 0;
  char *key = strs[i];
  while(key != NULL) {
    // Get the max length of the words for formatting
    MAX_STR_LEN = MAX_STR_LEN > strlen(key) ? MAX_STR_LEN : strlen(key);

    gpointer tmp_val = g_tree_lookup(cnts, key);
    if(tmp_val == NULL) {
      gpointer val = GINT_TO_POINTER(1);
      g_tree_insert(cnts, key, val);
      // g_printf("%s's current value is %d\n", key, GPOINTER_TO_INT(val));
    } else {
      gpointer val = GINT_TO_POINTER(GPOINTER_TO_INT(tmp_val) + 1);
      g_tree_insert(cnts, key, val);
      // g_printf("%s's current value is %d\n", key, GPOINTER_TO_INT(val));
    }
    key = strs[++i];
  }

  g_tree_remove(cnts, "");

  return cnts;
}

gboolean print_node (gpointer key, gpointer value, gpointer data)
{
  // int val = ;
  g_printf("%*s %d\n", 0 - ((int)MAX_STR_LEN + 2), (char *)key, GPOINTER_TO_INT(value));
  (void) data;

  return FALSE;
}

// void print_word_freq(GTree *counts)
// {
//   g_tree_foreach(counts, print_node, NULL);
// }

int main(int argc, char *argv[])
{
  GIOChannel *file = NULL;
  gchar *contents = NULL;
  gsize len;
  GError *e = NULL;

  if (argc != 2) {
    printf("Usage: %s <file>\n", argv[0]);
    // return EXIT_FAILURE;
    return 1;
  }

  // Open the file
  file = g_io_channel_new_file(argv[1], "r", &e);

  // Read the contents of the file
  g_io_channel_read_to_end(file, &contents, &len, &e);

  // Close the file
  g_io_channel_shutdown(file, TRUE, &e);

  // Convert to lowercase
  gchar *cont_lower = g_utf8_strdown(contents, len);

  // Remove punctuation
  gchar **words = g_strsplit_set(cont_lower, "!\"#$%%&\'()*+,-./:;<=>?@[\\]^_`{|}~ \n",-1);

  // Count word frequency
  GTree *counts = count_word_freq(words);

  // print_word_freq(counts);
  g_tree_foreach(counts, print_node, NULL);

  g_tree_destroy(counts);


  return 1;

}
