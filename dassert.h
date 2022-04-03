#ifndef DASSERT_H_
#define DASSERT_H_

#if DEBUG
#include <cassert>
#define dassert(x) assert(x)
#else
#define dassert(x) ((void)0)
#endif

#endif
