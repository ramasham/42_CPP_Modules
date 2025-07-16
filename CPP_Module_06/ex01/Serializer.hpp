#ifndef SERIALIZAER_HPP
#define SERIALIZAER_HPP

#include "Data.hpp"

typedef unsigned long uintptr_t;

class  Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        virtual ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};
#endif