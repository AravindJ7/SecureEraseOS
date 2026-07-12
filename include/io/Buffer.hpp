#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <cstdint>

class Buffer
{
public:

    std::vector<uint8_t> data;

public:

    Buffer();

    explicit Buffer(size_t size);

    size_t size() const;
};

#endif