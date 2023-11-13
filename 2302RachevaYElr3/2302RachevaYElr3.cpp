#include <iostream>
#include "def.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    ifstream in;
    ofstream out, out_time, out_h;

    in.open("in.txt");
    out.open("out.txt");
    out_time.open("time.txt", ios::app);
    out_h.open("h.txt", ios::app);

    int a = 0, count = 0, count_elem = 0, tmp = 0;
    avl_node* root_avl = NULL;
    bst_node* root_bst = NULL;
    rbt_node* root_rbt = NULL;

    avl_node* node_avl = NULL;
    bst_node* node_bst = NULL;
    rbt_node* node_rbt = NULL;

    cout << "1. Создать бинарное дерево поиска.\n2. Создать красно-черное дерево.\n3. Создать авл-дерево.\n"
        "4. Вставка в bst.\n5. Вставка в rbt.\n6. Вставка в avl.\n7. Удаление из bst."
        "\n8. Удаление из rbt.\n9. Удаление из avl.\n10. Найти минимальный и максимальный элемент в bst.\n"
        "11. Найти минимальный и максимальный элемент в rbt.\n12. Найти минимальный и максимальный элемент в avl.\n"
        "13. Завершить работу программы.\n";



    while (a != 13 && count < 3) {
        count = 0;
        cout << "\nВведите номер функции, которую необходимо выполнить: ";

        cin >> a;

        while (!cin || a < 1 || a > 13) {
            count += 1;
            if (count == 3) { cout << "Попытки израсходованы."; return 0; }
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
            cout << "\nНеверный формат ввода. Введите число от 1 до 12: ";
            cin >> a;
        }

        switch (a) {
        case 1:
            //создать bst
            count_elem = 0;
            root_bst = Create_bst(in, out, count_elem);
            out_h << count_elem << ' ' << Height_bst(root_bst) - 1 << endl;
            break;

        case 2:
            //создать rbt
            count_elem = 0;
            root_rbt = Create_rbt(in, out, count_elem, out_time);
            out_h << count_elem << ' ' << Height_rbt(root_rbt) - 1 << endl;
            break;

        case 3:
            //создать avl
            count_elem = 0;
            root_avl = Create_avl(in, out, count_elem, out_time);
            out_h << count_elem << ' ' << root_avl->h - 1<< endl;
            break;

        case 4:
            //вставка bst
            count_elem = 1;

            cout << "\nВведите значение: ";
            cin >> tmp;

            node_bst = CreateNode_bst(tmp);

            if (!root_bst) {
                root_bst = node_bst;
            }
            else {
                Insert_bst(&root_bst, node_bst);
            }

            out_h << count_elem << ' ' << Height_bst(root_bst) - 1 << endl;

            break;

        case 5:
            //вставка rbt
            count_elem = 1;

            cout << "\nВведите значение: ";
            cin >> tmp;

            node_rbt = CreateNode_rbt(tmp);

            if (!root_rbt) root_rbt = node_rbt;
            else Insert_rbt(&root_rbt, node_rbt, out_time);

            out_h << count_elem << ' ' << Height_rbt(root_rbt) - 1 << endl;
            break;

        case 6:
            //вставка avl
            count_elem = 1;

            cout << "\nВведите значение: ";
            cin >> tmp;

            if (!root_avl) root_avl = CreateNode_avl(tmp);
            else  Insert_avl(root_avl, tmp, out_time);

            //out_time << ' ' << count_elem << '\n';
            if (root_avl) out_h << count_elem << ' ' << (root_avl->h) - 1 << endl;

            break;

        case 7:
            //Удаление из bst

            cout << "\nВведите значение элемента, который необходимо удалить: ";
            cin >> tmp;

            node_bst = Search_bst(root_bst, tmp);
            
            if (!node_bst) {
                cout << "\nЭлемент не найден";
            }
            else {
                Delete_bst(&root_bst, node_bst);
            }

            break;

        case 8:
            //Удаление из rbt
            out_time << "\nудаление rbt\n";

            cout << "\nВведите значение элемента, который необходимо удалить: ";
            cin >> tmp;

            count_elem = 1;

            node_rbt = Search_rbt(root_rbt, tmp);

            /*while (node_rbt != root_rbt) {
                node_rbt = MaxElem_rbt(root_rbt);
                Delete_rbt(&root_rbt, node_rbt, out_time);
            }

            out_h << "\n----------RESULT--------------\n";
            count_elem = Inorder_rbt(root_rbt, out, count_elem);

            out_h << count_elem;*/
            

            if (!node_rbt) {
                cout << "\nЭлемент не найден";
            }
            else {
                Delete_rbt(&root_rbt, node_rbt, out_time);

                out_h << "\n----------RESULT--------------\n";
                Inorder_rbt(root_rbt, out, count_elem);

                out_h << count_elem;
            }

            //out_time << ' ' << count_elem << '\n';

            break;

        case 9:
            //Удаление из avl
            out_time << "\nудаление avl\n";

            cout << "\nВведите значение элемента, который необходимо удалить: ";
            cin >> tmp;

            count_elem = 1;

            //avl_node* n2 = Search_avl(root_avl, tmp);
            Delete_avl(root_avl, tmp, out_time);

            out_h << "\n----------RESULT AVL--------------\n";
            Inorder_avl(root_avl, out, count_elem);
            out_h << count_elem;


            //out_time << ' ' << count_elem << '\n';

            break;

        case 10:
            if (!root_bst) cout << "Нельзя выполнить функцию";

            else {
                node_bst = MinElem_bst(root_bst);
                cout << "\nМинимальный элемент: " << node_bst->key;

                node_bst = MaxElem_bst(root_bst);
                cout << "\nМаксимальный элемент: " << node_bst->key;
            }

            break;

        case 11:
            if (!root_rbt) cout << "\nНельзя выполнить функцию.";

            else {
                node_rbt = MinElem_rbt(root_rbt);
                cout << "\nМинимальный элемент: " << node_rbt->key;

                node_rbt = MaxElem_rbt(root_rbt);
                cout << "\nМаксимальный элемент: " << node_rbt->key;
            }

            break;

        case 12:
            if (!root_avl) cout << "\nНельзя выполнить функцию.";

            else {
                node_avl = MinElem_avl(root_avl);
                cout << "\nМинимальный элемент: " << node_avl->key;

                node_avl = MaxElem_avl(root_avl);
                cout << "\nМаксимальный элемент: " << node_avl->key;
            }

            break;

        default:
            break;
        }
    }

    in.close();
    out.close();
    out_time.close();
    out_h.close();
}

