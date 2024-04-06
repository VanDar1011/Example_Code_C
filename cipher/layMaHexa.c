#include <stdio.h>
void displayState(unsigned char* state) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", state[i]);
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
}
void writeHexToFile(FILE* file, const char* buffer, size_t size) {
    for (size_t i = 0; i < size; i++) {
        fprintf(file, "%02X", (unsigned char)buffer[i]);
    }
}
int main() {
    FILE* inputFile, * outputFile;
    unsigned char buffer[32];
    ///size_t bytesRead;
    int bufferIndex = 0;

    // Mở tập tin
    if (fopen_s(&inputFile, "output.txt", "rb") != 0) {
        printf("Không thể mở tập tin.\n");
        fclose(inputFile);
        return 1;
    }
    //if (fopen_s(&outputFile, "output.txt", "wb") != 0) {
    //    printf("Không thể mở tập tin output.\n");
    //    fclose(outputFile); // Đóng tập tin input trước khi thoát
    //    return 1;
    //}
    /*while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        writeHexToFile(outputFile, buffer, bytesRead);
        fprintf(outputFile, "\n"); 
    }*/
    unsigned char byte1, byte2;
    // Đọc 2 giá trị liên tiếp từ tập tin và lưu vào buffer cho tới khi buffer đủ 16 phần tử
    while (fscanf_s(inputFile, "%02hhx%02hhx", &byte1, &byte2) == 2) {
        buffer[bufferIndex++] = byte1;
        buffer[bufferIndex++] = byte2;
        if (bufferIndex == 16) {
            // Ghi buffer vào tập tin output
          //  writeHexToFile(outputFile, buffer, 16);
           // fprintf(outputFile, "\n");
            displayState(buffer);

            bufferIndex = 0; // Đặt lại chỉ số của buffer về 0
        }
    }

    // Đóng tập tin
    fclose(inputFile);
    //fclose(outputFile);
    return 0;
}
