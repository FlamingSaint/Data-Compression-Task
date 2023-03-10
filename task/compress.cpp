#include <iostream>
#include <fstream>
#include <zlib.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Open the input file for reading
    std::ifstream input(argv[1], std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Failed to open input file: " << argv[1] << std::endl;
        return 1;
    }

    // Open the output file for writing
    std::string output_file = std::string(argv[1]) + ".gz";
    gzFile output = gzopen(output_file.c_str(), "wb");
    if (!output) {
        std::cerr << "Failed to open output file: " << output_file << std::endl;
        return 1;
    }

    // Compress the input and write it to the output file
    char buffer[1024];
    int bytes_read;
    long long total_bytes_read = 0;
    while ((bytes_read = input.readsome(buffer, sizeof(buffer))) > 0) {
        int bytes_written = gzwrite(output, buffer, bytes_read);
        if (bytes_written == 0) {
            std::cerr << "Failed to compress data" << std::endl;
            return 1;
        }
        total_bytes_read += bytes_read;
    }

    // Close the input and output files
    input.close();
    gzclose(output);

    // Print informative metrics about the compression
    std::ifstream compressed(output_file, std::ios::binary);
    if (!compressed.is_open()) {
        std::cerr << "Failed to open compressed file: " << output_file << std::endl;
        return 1;
    }
    compressed.seekg(0, std::ios::end);
    long long compressed_size = compressed.tellg();
    std::cout << "Original size: " << total_bytes_read << " bytes" << std::endl;
    std::cout << "Compressed size: " << compressed_size << " bytes" << std::endl;
    std::cout << "Compression ratio: " << static_cast<double>(total_bytes_read) / compressed_size << std::endl;

    return 0;
}
