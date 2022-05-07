#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

struct request_entry {
    int size;
    int id;
};

map<int, int> free_blocks_id;            // 1 = id, 2 = size
multimap<int, int> free_blocks_size;     // 1 = size, 2 = id

void add_block(int id, int size) {
    free_blocks_id.insert( { id, size } );
    free_blocks_size.insert( { size, id } );
}

void remove(map<int, int>::iterator& a) {
    auto b = free_blocks_size.find(a -> second);
    while (b -> second != a -> first) b++;
    free_blocks_size.erase(b);
    free_blocks_id.erase(a);
}

int main() {
    int max_size, req_count, id, size;
    cin >> max_size >> req_count;
    request_entry requests[req_count];
    add_block(1, max_size);

    for (int curr_req_id = 0; curr_req_id < req_count; curr_req_id++) {
        int input; cin >> input;

        if (input > 0) {

            //--------------------------------
            // ASSIGN BLOCKS
            //--------------------------------

            auto selected_block = free_blocks_size.lower_bound(input);
            if (selected_block == free_blocks_size.end()) id = -1;
            else {
                id = selected_block->second;
                int new_id = id + input;
                size = selected_block->first - input;

                free_blocks_id.erase(selected_block->second);
                free_blocks_size.erase(selected_block);

                if (size != 0) add_block(new_id, size);
            }
            cout << id << endl;

        }
        else {

            //--------------------------------
            // FREE BLOCKS
            //--------------------------------

            int id_x = requests[abs(input) - 1].id;
            int size_x = requests[abs(input) - 1].size;
            if (id_x == -1) continue;

            auto right = free_blocks_id.lower_bound(id_x);
            auto left = (right != free_blocks_id.begin()) ? prev(right) : free_blocks_id.end();

            if (right != free_blocks_id.end() && right->first == id_x + size_x){
                if (left != free_blocks_id.end() && left->first + left->second == id_x) {
                    id = left->first;
                    size = left->second + right->second;
                    remove(left);
                    remove(right);
                    add_block(id, size + size_x);
                } else {
                    size = right->second;
                    remove(right);
                    add_block(id_x, size + size_x);
                }
            } else {
                if (left != free_blocks_id.end() && left->first + left->second == id_x) {
                    id = left->first;
                    size = left->second;
                    remove(left);
                    add_block(id, size + size_x);
                } else add_block(id_x, size_x);
            }
        }
        requests[curr_req_id] = {input, id};
    }
}

/*
Пете поручили написать менеджер памяти для новой стандартной библиотеки языка \varphi++. В распоряжении у менеджера находится массив из N последовательных ячеек памяти, пронумерованных от 1 до N. Задача менеджера – обрабатывать запросы приложений на выделение и освобождение памяти. Запрос на выделение памяти имеет один параметр K. Такой запрос означает, что приложение просит выделить ему K последовательных ячеек памяти. Если в распоряжении менеджера есть хотя бы один свободный блок из K последовательных ячеек, то он обязан в ответ на запрос выделить такой блок. При этом непосредственно перед самой первой ячейкой памяти выделяемого блока не должно располагаться свободной ячейки памяти. После этого выделенные ячейки становятся занятыми и не могут быть использованы для выделения памяти, пока не будут освобождены. Если блока из K последовательных свободных ячеек нет, то запрос отклоняется. Запрос на освобождение памяти имеет один параметр T. Такой запрос означает, что менеджер должен освободить память, выделенную ранее при обработке запроса с порядковым номером T. Запросы нумеруются, начиная с единицы. Гарантируется, что запрос с номером T – запрос на выделение, причем к нему еще не применялось освобождение памяти. Освобожденные ячейки могут снова быть использованы для выделения памяти. Если запрос с номером T был отклонен, то текущий запрос на освобождение памяти игнорируется. Требуется написать менеджер памяти, удовлетворяющий приведенным критериям.
Формат ввода

Первая строка входного файла содержит числа N и M – количество ячеек памяти и количество запросов соответственно (1 ≤ N ≤ 231 - 1; 1 ≤ M ≤ 105). Каждая из следующих M строк содержит по одному числу: (i+1)-я строка входного файла (1 ≤ i ≤ M) содержит либо положительное число K, если i-й запрос – запрос на выделение с параметром K (1 ≤ K ≤ N), либо отрицательное число -T, если i-й запрос – запрос на освобождение с параметром T (1 ≤ T < i).
Формат вывода

Для каждого запроса на выделение памяти выведите в выходной файл результат обработки этого запроса: для успешных запросов выведите номер первой ячейки памяти в выделенном блоке, для отклоненных запросов выведите число -1. Результаты нужно выводить в порядке следования запросов во входном файле. 
*/