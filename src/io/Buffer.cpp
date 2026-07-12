#include "io/Buffer.hpp"

Buffer::Buffer()
{
}

Buffer::Buffer(size_t size)
{
    data.resize(size);
}

size_t Buffer::size() const
{
    return data.size();
}