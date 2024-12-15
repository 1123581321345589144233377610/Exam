#include <iostream>
#include <cassert>

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* Process(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

ListNode* CreateNode(int value) {
    ListNode* newNode = new ListNode();
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

void PrintList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void FreeList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void TestEmptyList() {
    ListNode* head = nullptr;
    head = Process(head);
    assert(head == nullptr);
    std::cout << "TestEmptyList passed!" << std::endl;
}

void TestSingleElementList() {
    ListNode* head = CreateNode(1);
    head = Process(head);
    assert(head != nullptr && head->value == 1 && head->next == nullptr);
    FreeList(head);
    std::cout << "TestSingleElementList passed!" << std::endl;
}

void TestLargeList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < 10; ++i) {
        ListNode* newNode = CreateNode(i);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = Process(head);

    ListNode* current = head;
    for (int i = 9; i >= 0; --i) {
        assert(current != nullptr && current->value == i);
        current = current->next;
    }

    assert(current == nullptr);
    FreeList(head);
    std::cout << "TestLargeList passed!" << std::endl;
}

int main() {
    // TestEmptyList();
    // TestSingleElementList();
    // TestLargeList();
    // std::cout << "All tests passed!" << std::endl;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    std::cout << "Введите элементы списка (завершите ввод любым нечисловым значением):" << std::endl;

    int value;
    while (std::cin >> value) {
        ListNode* newNode = CreateNode(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    std::cout << "Исходный список:" << std::endl;
    PrintList(head);

    head = Process(head);

    std::cout << "Развернутый список:" << std::endl;
    PrintList(head);

    FreeList(head);

    return 0;
}
