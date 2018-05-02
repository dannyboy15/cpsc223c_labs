/* Daniel Bravo
 * 2018-04-11
 * CPSC 223C-01/02
 * Lab 10
 */

#include <ctype.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <string.h>

gint tree_cmp_func(gconstpointer a, gconstpointer b)
{
  return strcmp(a,b);
}

GTree * count_word_freq(gchar **strs)
{
  GTree *counts = g_tree_new(tree_cmp_func);

  int i = 0;
  char *key = strs[i];
  while(key != NULL) {
    gpointer tmp_val = g_tree_lookup(counts, key);
    if(tmp_val == NULL) {
      int val = 1;
      g_tree_insert(counts, key, &val);
    } else {
      int val = GPOINTER_TO_INT(tmp_val) + 1;
      g_tree_replace(counts, key, &val);
    }
    key = strs[++i];
  }

  return counts;
}

int main(int argc, char *argv[])
{
  GIOChannel *file;
  gchar *contents;
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

  // Convert to lowercase
  gchar *cont_lower = g_utf8_strdown(contents, len);

  // Remove punctuation
  gchar **words = g_strsplit_set(cont_lower, "!\"#$%%&\'()*+,-./:;<=>?@[\\]^_`{|}~",-1);

  // Count word frequency
  GTree *counts = count_word_freq(words);

  (void) counts;

  g_printf("%s\n%lu\n", words[0], len);

  return 1;

}
