#ifndef TASK_7_H
#define TASK_7_H
constexpr unsigned short size{4};
auto Faza() -> void;
void printArray(char(&ref_array)[size]);
void swap(char(&ref_array)[size], int i, int j);
bool shifts(char(&ref_array)[size]);
#endif // TASK_7_H
