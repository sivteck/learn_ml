#include <iostream>
#include <string>

// STB Image libraries
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_jpeg> <output_jpeg>" << std::endl;
        return 1;
    }
    
    const char* input_path = argv[1];
    const char* output_path = argv[2];
    
    // Load image
    int width, height, channels;
    unsigned char* image = stbi_load(input_path, &width, &height, &channels, 0);
    
    if (!image) {
        std::cerr << "Error loading image: " << input_path << std::endl;
        return 1;
    }
    
    std::cout << "Loaded image: " << width << "x" << height << " with " << channels << " channels" << std::endl;
    
    // Allocate memory for grayscale image
    unsigned char* gray_image = new unsigned char[width * height];
    
    // Convert to grayscale
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * channels;
            
            // Standard RGB to grayscale conversion
            // Y = 0.299R + 0.587G + 0.114B
            if (channels >= 3) {
                unsigned char r = image[pixel_index];
                unsigned char g = image[pixel_index + 1];
                unsigned char b = image[pixel_index + 2];
                
                gray_image[y * width + x] = static_cast<unsigned char>(
                    0.299f * r + 0.587f * g + 0.114f * b
                );
            } else {
                // If it's already grayscale, just copy
                gray_image[y * width + x] = image[pixel_index];
            }
        }
    }
    
    // Save the grayscale image
    int success = stbi_write_jpg(output_path, width, height, 1, gray_image, 90);
    
    if (!success) {
        std::cerr << "Error writing output image: " << output_path << std::endl;
    } else {
        std::cout << "Successfully saved grayscale image to: " << output_path << std::endl;
    }
    
    // Clean up
    stbi_image_free(image);
    delete[] gray_image;
    
    return 0;
}
