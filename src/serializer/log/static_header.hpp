#ifndef SERIALIZER_LOG_STATIC_HEADER_HPP_
#define SERIALIZER_LOG_STATIC_HEADER_HPP_

#include <stddef.h>
#include "arch/types.hpp"

struct static_header_t {
    char software_name[16];
    char version[16];
    char data[0];
};

bool static_header_check(direct_file_t *file);

struct static_header_write_callback_t {
    virtual void on_static_header_write() = 0;
    virtual ~static_header_write_callback_t() {}
};

void co_static_header_write(direct_file_t *file, void *data, size_t data_size);

bool static_header_write(direct_file_t *file, void *data, size_t data_size, static_header_write_callback_t *cb);

struct static_header_read_callback_t {
    virtual void on_static_header_read() = 0;
    virtual ~static_header_read_callback_t() {}
};

bool static_header_read(direct_file_t *file, void *data_out, size_t data_size, static_header_read_callback_t *cb);

#endif /* SERIALIZER_LOG_STATIC_HEADER_HPP_ */
