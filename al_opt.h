#ifndef AL_OPT_H
#define AL_OPT_H

#include <stdbool.h>

struct al_opt
{
    char const *long_name;
    char const short_name;
    char const *arg_name;
    char const *arg_doc;
    bool is_flag;
};

#define AL_USAGE_SHORT_NAME -1

#define opt_count(a) (sizeof(a) / sizeof(struct al_opt))

struct al_opt const *opt_get(int nopts, struct al_opt const *opts,
                             char const *arg);

#define AL_HELP_OPT                                                            \
    {                                                                          \
        "help", '?', 0, "Give this help list", true                            \
    }
#define AL_USAGE_OPT                                                           \
    {                                                                          \
        "usage", AL_USAGE_SHORT_NAME, 0, "Give a short usage message", true    \
    }

#define AL_DEFAULT_OPTS AL_HELP_OPT, AL_USAGE_OPT,

#endif
