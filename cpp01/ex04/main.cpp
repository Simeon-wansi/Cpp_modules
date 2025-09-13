/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:55:13 by sngantch          #+#    #+#             */
/*   Updated: 2025/07/31 14:43:47 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string customReplace (std::string &original, std::string &target ,std::string& replacement)
{
    std::string result = "";
    size_t start_pos = 0;
    size_t found_pos;

    while( (found_pos = original.find(target, start_pos)) != std::string::npos)
    {
        result += original.substr(start_pos, found_pos - start_pos); // Append the part before the target
        result += replacement; // Append the replacement
        start_pos = found_pos + target.length(); // Movve the past target
    }
    result += original.substr(start_pos); // Append the rest of the original string
    return (result);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error, Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
     
    if (s1.empty())
    {
        std::cerr << "Error: search string  can't be empty" << std::endl;
        return (1);
    }
    
    //Open input file
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: can't open file " << filename << std::endl;
        return (1);
    }
    
    // Create the output file
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open())
    {
        std::cerr << "Error: can't create file " << outputFilename << std::endl;
        inputFile.close();
        return (1);
    }
    
    //Read neter file content
    std::string content;
    std::string line;
    
    //Read file content
    while(std::getline(inputFile, line))
    {
        content += line+ "\n";
    }
    if (!content.empty() && content.back() == '\n') {
        content.pop_back();  // Remove last \n
    }
    // Replace s1 with s2
    std::string result = customReplace(content, s1, s2);
    outputFile << result;
    
    //Close files
    inputFile.close();
    outputFile.close();
    
    return (0); 
}