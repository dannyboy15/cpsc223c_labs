/* Daniel Bravo
 * 2018-05-16
 * CPSC 223C-01/02
 * Lab 12
 */

#ifndef _PERSON_H
#define _PERSON_H

#include <glib-object.h>

#define TYPE_PERSON (person_get_type())
#define PERSON(object) \
  (G_TYPE_CHECK_INSTANCE_CAST((object), TYPE_PERSON, Person))
#define EXAMPLE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_PERSON, PersonClass))

typedef struct _PersonClass
{
  GObjectClass parent_class;

  void (*person_greet)(Person *self);
} PersonClass;

typedef struct _Person
{
  GObjectClass parent_instance;

  char *name;
} Person;

Gtype person_get_type(void);

#endif
