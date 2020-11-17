# coding style conventions and guide

## Name Conventions

TypeName
localVariable
RoutineName
routineParameter

## Standard Affixes

## Anatomy of a header file

```C
#if !defined(INCLUDED_LIBRARY_HEADER_FILE)
#define INCLUDED_LIBRARY_HEADER_FILE

#include <forge/forge.h>

/* <...Types> <...Typedefs> */
/* <...Macros> */

FORGE_BEGIN_DECLS

/* <...FunctionPrototypes> */

FORGE_END_DECLS

#endif
```

## Anatomy of a source file

```C
#include <library/public.h>
#include <library/internal.h>

/* <...functions> */
```