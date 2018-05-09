/* Daniel Bravo
 * 2018-05-16
 * CPSC 223C-01/02
 * Lab 12
 */

#include "person.h"

G_DEFINE_TYPE (Person, person, G_TYPE_OBJECT);

static void person_class_init (PersonClass* klass)
{
  GObjectClass	*g_object_class;

  g_object_class = G_OBJECT_CLASS(klass);

  klass->greet_person = greet_person_impl;
}

static void person_init (Person *self)
{
  self->name = NULL;
}

void person_greet_impl(Person *self)
{
  printf("Hello %s\n", self->name);
}
