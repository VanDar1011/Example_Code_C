#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getInputKey(unsigned char key[16]) {
    char input[20]; // Mảng để lưu 16 ký tự nhập từ bàn phím, kèm theo ký tự kết thúc chuỗi '\0'

    // Nhập chuỗi từ bàn phím
    printf("Nhập 16 ký tự bất kỳ: ");
    fgets(input, sizeof(input), stdin);

    // Kiểm tra độ dài chuỗi nhập vào
    if (strlen(input) != 17 || input[16] != '\n') {
        printf("Số lượng ký tự không đúng. Vui lòng nhập đúng 16 ký tự bất kỳ.\n");
        exit(1);
    }

    // Chuyển đổi chuỗi nhập vào thành mảng unsigned char
    for (int i = 0; i < 16; i++) {
        key[i] = input[i]; // Giữ nguyên ký tự đầu vào
    }
}
void displayState(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", state[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}

int main() {
    unsigned char key[16];

    // Lấy 16 ký tự từ bàn phím
    getInputKey(key);

    // In ra mảng key
    displayState(key);
    return 0;
}
