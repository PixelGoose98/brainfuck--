# BF-- brainfuck-- 0.1
a alpha version of a better version of the interpreter based brainfuck programing language with more commands and capabilities (alpha ver 0.1) all in one file! its BF-- 0.1! compiler ver coming soon...
ALSO ITS BACKWARD COMPATIBLE WITH BRAINFUCK, JUST WRITE YOUR BF CODE IN THE BF-- FILE EXTENSION (.bfmm)

  **WARNING, THIS HAS NOT BEEN TESTED, IF ANY BUGS ARE FOUND PLEASE CONTACT pixelgoose98@gmail.com, AND if you can, check the source code of the language and try to fix it urself, dont worry, its fairly simple... i think**

HOW TO USE:
  **1** GO TO FOLDER THAT IS THE LOCATION OF THE COMPILED C++ FILE
  **2** THEN PUT YOUR BRAINFUCK-- FILE (.bfmm) IN THE SAME FOLDER
  **3** OPEN COMMAND PROMPT, TYPE THE COMPILED .EXE FILE NAME AND THEN THE BRAINFUCK-- FILENAME WITH THE EXTENSION, SO eg. C:\Users\Admin>bfmmcomp main.bfmm
  **4** output will appear in command prompt

WHAT WAS ADDED AND DESCRIPTION:
  >all commands in BF--<:
      '>': Increment the pointer to point to the next memory cell.
      '<': Decrement the pointer to point to the previous memory cell.
      '+': Increment the value in the current memory cell by 1.
      '-': Decrement the value in the current memory cell by 1.
      '.': Output the ASCII value of the character in the current memory cell.
      ',': Input a character and store its ASCII value in the current memory cell.
      '[': If the value in the current memory cell is 0, jump to the corresponding ']' command.
      ']': If the value in the current memory cell is not 0, jump back to the corresponding '[' command.
      ':': Output the ASCII value of the character in the current memory cell.
      ';: Input a character and store its ASCII value in the current memory cell.
      '@': Reset the value in the current memory cell to 0.
      '#': Reset the value in the current memory cell to 0 and reset the pointer to the beginning of the memory.
      '&': Store the current pointer value in the current memory cell.
      '!': Store the size of the input buffer in the current memory cell.
      '?': If the input buffer is empty, set the value in the current memory cell to 0; otherwise, set it to 1.
      '^': Move the pointer left by one cell.
      '$': Move the pointer right by one cell.
      '*': Multiply the value in the current memory cell by 2.
      `'/': Divide the value in the current memory cell by 2.
      '%': Perform modulo operation on the value in the current memory cell.
      '~': Perform bitwise negation on the value in the current memory cell.
      '{': Move the pointer left by 10 cells.
      '}': Move the pointer right by 10 cells.
      '(': If the value in the current memory cell is not 0, jump to the corresponding ')' command.
      ')': If the value in the current memory cell is 0, jump back to the corresponding '(' command.
