# 📦 DAA Project Huffman-Coding

📌 Overview

This project implements Huffman Coding, a classic lossless data compression technique used widely in file formats and communication systems.
The program:

Builds a Huffman Tree based on character frequencies

Generates prefix-free binary codes

Encodes a given input string

Compares original size vs compressed size

Demonstrates the efficiency of Huffman compression




🚀 Features

✔ Builds Huffman Tree using a Min-Heap
✔ Generates optimal prefix codes
✔ Compresses input text
✔ Calculates compression ratio
✔ Supports any character-frequency input
✔ Clean and understandable implementation in C++



🧩 Code Structure

Main Components

Component	Description

Node	Represents each character node in the Huffman tree
Compare	Comparator for priority queue (min-heap)
buildTree()	Builds Huffman tree based on frequency map
generateCodes()	Generates binary codes for each character
encodeString()	Compresses the input text using Huffman codes
main()	Handles input, output, and running all steps



📘 Sample Input Format

Enter number of characters: 4
Enter characters and their frequencies:
a 5
b 9
c 12
d 13
Enter the text you want to encode: abcd



🖥 Output Example

Huffman Codes:
a : 110
b : 10
c : 0
d : 111

Original Size: 32 bits
Compressed Size: 9 bits
Encoded Text: 1101010111



🧮 Time Complexity Analysis

1️⃣ Building Frequency Map:

O(n) — one pass through input text.

2️⃣ Building Huffman Tree (Priority Queue Operations):

O(m log m)

m = number of unique characters

Each push/pop on priority queue costs log m.


3️⃣ Generating Codes:

O(m) — DFS traversal of the tree.

4️⃣ Encoding Text:

O(n) — replacing characters with their Huffman codes.

➡️ Total Complexity:

O(n + m log m)

For ASCII (max 256 chars), tree-building cost is small → effectively O(n).



📊 Comparison With Other Compression Techniques

Compression Method	Type	Strengths	Weaknesses

Huffman Coding	Lossless	Fast, simple, prefix-free codes	Does not detect repeated patterns
LZ77 / LZW	Lossless	Compresses repeated sequences	More complex
Arithmetic Coding	Lossless	Achieves compression closer to entropy	Slower, complex
RLE	Lossless	Great for images with large repeated values	Poor for text


Where Huffman Performs Best

When certain characters appear more frequently

When input data has skewed frequency distribution



---

🌍 Real-Time Applications of Huffman Coding

✔ 1. Image Compression (JPEG)

Used to encode quantized DCT coefficients.

✔ 2. PNG File Compression

DEFLATE algorithm = LZ77 + Huffman Coding.

✔ 3. MP3 / Audio Compression

Encodes quantized frequency components.

✔ 4. Data Transmission Protocols

Efficient encoding of frequent control characters.

✔ 5. File Archivers (ZIP, GZIP)

Uses Huffman as the entropy coding stage.

✔ 6. Embedded Systems

Low-power devices use Huffman due to its simplicity.

✔ 7. Text Compression

Telecom SMS compression, log compression, domain-specific data compression.


📁 Project Files

.
├── huffman.cpp          # Main program
├── README.md            # Documentation
└── examples/            # Sample input/output cases


🛠 How to Compile & Run

Compile

g++ huffman.cpp -o huffman

Run

./huffman


🤝 Contributing

Pull requests are welcome!
Feel free to improve documentation, optimize code, or add new features like:

File-based compression

Decoding support

Canonical Huffman codes



📜 License

This project is released under the MIT License.
