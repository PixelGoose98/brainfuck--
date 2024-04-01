#include <iostream>
#include <fstream>
#include <vector>

class BrainfuckInterpreter {
private:
    std::vector<char> memory;
    int pointer;
    std::vector<char> inputBuffer;

public:
    BrainfuckInterpreter() : memory(30000, 0), pointer(0), inputBuffer() {}

    void interpret(const std::string& code) {
        int codeLength = code.length();
        int instructionPointer = 0;

        while (instructionPointer < codeLength) {
            char instruction = code[instructionPointer];
            switch (instruction) {
                case '>':
                    pointer++;
                    break;
                case '<':
                    pointer--;
                    break;
                case '+':
                    memory[pointer]++;
                    break;
                case '-':
                    memory[pointer]--;
                    break;
                case '.':
                    std::cout << memory[pointer];
                    break;
                case ',':
                    if (!inputBuffer.empty()) {
                        memory[pointer] = inputBuffer.front();
                        inputBuffer.erase(inputBuffer.begin());
                    } else {
                        std::cin >> memory[pointer];
                    }
                    break;
                case '[':
                    if (memory[pointer] == 0) {
                        int loopCount = 1;
                        while (loopCount > 0) {
                            instructionPointer++;
                            if (code[instructionPointer] == '[') loopCount++;
                            else if (code[instructionPointer] == ']') loopCount--;
                        }
                    }
                    break;
                case ']':
                    if (memory[pointer] != 0) {
                        int loopCount = 1;
                        while (loopCount > 0) {
                            instructionPointer--;
                            if (code[instructionPointer] == '[') loopCount--;
                            else if (code[instructionPointer] == ']') loopCount++;
                        }
                    }
                    break;
                // Additional Commands
                case ':':
                    std::cout << static_cast<int>(memory[pointer]);
                    break;
                case ';':
                    memory[pointer] = static_cast<char>(std::getchar());
                    break;
                case '@':
                    memory[pointer] = 0;
                    break;
                case '#':
                    memory[pointer] = 0;
                    pointer = 0;
                    break;
                case '&':
                    memory[pointer] = pointer;
                    break;
                case '!':
                    memory[pointer] = static_cast<char>(inputBuffer.size());
                    break;
                case '?':
                    if (inputBuffer.empty()) {
                        memory[pointer] = 0;
                    } else {
                        memory[pointer] = 1;
                    }
                    break;
                case '^':
                    if (pointer > 0) {
                        pointer--;
                    }
                    break;
                case '$':
                    if (pointer < memory.size() - 1) {
                        pointer++;
                    }
                    break;
                default:
                    // Ignore unrecognized characters
                    break;
            }
            instructionPointer++;
        }
    }

    void setInput(const std::string& input) {
        inputBuffer = std::vector<char>(input.begin(), input.end());
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename.bfmm>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::string code((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());

    BrainfuckInterpreter interpreter;
    interpreter.interpret(code);

    return 0;
}
