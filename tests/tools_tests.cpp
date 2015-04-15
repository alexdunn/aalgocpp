#include <vector>
#include <string>
#include <iostream>
#include <pthread.h>

//void *p;

// Definitions for Thread Sanitizer Test
//int Global;
//void *Thread1(void *x)
//{
//Global = 42;
//return x;
//}

void testTools()
{
    // Undefined Sanitizer Test
    // TODO(alexdunn)

    // clang static analyzer test
    //int y = 0;
    //y = 1;

    // flawfinder test
    //popen( "test", "r" );

    // Address Sanitizer Test
    //p = malloc(7);
    //p = 0; // The memory is leaked here.

    // clang-modernize test
    //int x = 0;
    //std::auto_ptr<int> a(new int(x));
    //std::auto_ptr<int> b;

    // Test clang-tidy by ptting a "" include before  a <> include at the top of the file

    // Memory Sanitizer Test
    //int x[10];
    //x[0] = 1;
    //if (x[argc])
    //{
    //std::cout << "1" << std::endl;
    //}

    // Thread Sanitizer Test
    //pthread_t t;
    //pthread_create(&t, NULL, Thread1, NULL);
    //Global = 43;
    //pthread_join(t, NULL);
}

