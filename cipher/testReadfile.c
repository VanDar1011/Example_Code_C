#include <stdio.h>
#include <stdint.h>
void displayState(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", state[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}
int main() {
    FILE* inputFile, * outputFile;
    unsigned char buffer[16];
    size_t bytesRead;

    // Mở tập tin
    if (fopen_s(&inputFile, "text.txt", "rb") != 0) {
        printf("Không thể mở tập tin.\n");
        return 1;
    }
    // if (fopen_s(&outputFile, "output.txt", "wb") != 0) {
    //     printf("Không thể mở tập tin output.\n");
    //     fclose(inputFile); // Đóng tập tin input trước khi thoát
    //     return 1;
    // }
    int flag = 1;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        // Xử lý dữ liệu ở đây
        // Ví dụ: In từng byte của buffer

        for (size_t i = bytesRead; i < sizeof(buffer); i++) {
            buffer[i] = ' '; // Thêm ký tự space vào buffer nếu số byte đọc ít hơn 16
        }
        if (flag == 1) {
            printf("\nvong 1\n");
            displayState(buffer);
            flag++;
        }
        else {
            printf("\nvong 2\n");
            displayState(buffer);
        }
        //displayState(buffer);

       //  fwrite(buffer, 1, bytesRead, outputFile);
       //  writeHexToFile(outputFile, buffer, bytesRead);
        // fprintf(outputFile, "\n"); // Xuống dòng sau mỗi dòng dữ liệu
          //displayState(buffer);
        /* for (size_t i = 0; i < bytesRead; i++) {
             printf("%02X ", (unsigned char)buffer[i]);
         }
         printf("\n");*/

    }

    // Đóng tập tin
    fclose(inputFile);
   // fclose(outputFile);
}
