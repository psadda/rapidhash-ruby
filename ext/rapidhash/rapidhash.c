#include "rapidhash.h"
#include "ruby.h"
#include "extconf.h"


#include <inttypes.h>

VALUE rapidhash_hash(VALUE self, VALUE data, VALUE seed)
{
    // Unpack the data argument
    Check_Type(data, T_STRING);
    void* c_data = RSTRING_PTR(data);
    size_t c_length = RSTRING_LEN(data);

    // Unpack the seed argument
    if (!FIXNUM_P(seed) && TYPE(seed) != T_BIGNUM) {
        rb_raise(rb_eTypeError, "seed must be Numeric");
    }
    uint64_t c_seed = (uint64_t)NUM2ULL(seed);

    return ULL2NUM(rapidhash_withSeed(c_data, c_length, c_seed));
}

void Init_rapidhash()
{
    VALUE mod = rb_define_module("RapidHash");
    rb_define_const(mod, "DEFAULT_SEED", ULL2NUM(RAPID_SEED));
    rb_define_module_function(mod, "rapid_hash", &rapidhash_hash, 2);
}
