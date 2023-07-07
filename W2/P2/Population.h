#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds{
    struct PostalCode{
        char* code;
        int population;
    };

    void sort();
    bool load(const char filename[]);
    bool load(PostalCode& post);
    void display(const PostalCode& code);
    void display();
    void deallocateMemory();

} 
#endif 