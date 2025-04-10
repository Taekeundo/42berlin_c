/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:26:22 by tkwak             #+#    #+#             */
/*   Updated: 2024/06/27 11:26:24 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>     // std::cout, std::endl
#include <string>       // std::string()
#include <fstream>      // std::ifstream(), std::ofstream()

/*  [F]
    [ Goal ]
    1. Finds all occurrences of the substring 's1' in 'content'.
    2. Replaces them with 's2'.

    [ How to proceed ]
    1. [ Method ] Find
        (*i) = (*content).find(*s1);
        
        Find the index of (s1).
        'i' is the first index that (*s1) was founded in (*content).

    2. [ Method ] erase
        (*content).erase((*i), (*s1).length());

        Delete (*i) as many as the length of (*s1).
        ex) s1 = "aaa" // length of s1 = 3
            (Before) content = "bbaaabb"
            (after)  contetn = "bb[][][]bb"
        = content에서 s1이 나타나는 위치부터 s1의 길이만큼의 문자를 삭제.

    3. [ Method ] insert
        (*content).insert((*i), (*s2));

        Insert the (*s2) from the index (*i).
        = content에서 s1이 삭제된 위치에 s2를 삽입.

    4. [ Method ] find
        (*i) = (*content).find(*s1);

        Update the *i for the new index(*s1 from the content).
    
    [ Memo ]
    (C++, std::string) provieds the 'find' member function.
    Nothing found in string, it returns 'std::string::npos'.
    
*/
void    erase_and_insert(int *i, std::string *s1, std::string *s2, std::string *content)
{
    (*i) = (*content).find(*s1);
    while ((*i) != std::string::npos)
    {
        (*content).erase((*i), (*s1).length());
        (*content).insert((*i), (*s2));
        (*i) = (*content).find(*s1);
    }
}

/*  [F]
    [ Goal of project ]
    1. Learn about file input, output (파일 입출력).
    2. Using 'string' member functions for editing the string.

    [ Background]
    1. fstream // 파일 입출력 헤더
        std::ifstream infile(filename);     // input
        std::ofstream outfile(filename);    // output
        std::fstream                        // input & output

    2. member functions
        infile.eof()    // 파일 읽기를 끝까지 마쳤는 지 확인할 수 있다.

        str.find(to_find);
            str에서 to_find가 있는지 찾아주는 함수.
            (if) true
                'to_find'문자열을 찾으면 -> 문자열의 첫번째 위치 반환.
            (else) false
                'to_find'문자열을 찾지 못하면 -> 엄청 큰 수 반환.
            (how) !! n != std::string::npos !!

        str.substr(n);
            str에서 n번째 위치부터 끝까지 문자열을 잘라서 반환.
        str.substr(n, to);
            str에서 n번째 위치부터 to번째 위치까지 잘라서 반환.

    [ What to do ]
    av[1]: filename     av[2]: s1       av[3]: s2

        mandatory
            1. open the (filename).
            2. cpy the (filename) to (filename.replace).

        condition
            1. replace (s1) to (s2).
            2. Can't use std::string::replace()
            3. Error handling (ac, av).
    
    [ Comparing ]
    (1) std::ifstream infile(av[1]);
        = Make the object(name: infile) and
          initialize the object(name: infile) at the same time.
        = Don't need to use "open" method.
          !! Automatically (file) can be opened !!

    (2) std::ifstream  infile;
        infile.open(av[1]);
        = Make the object first and
          Open the file passively with using 'open' method.
*/
int main(int ac, char **av)
{
    // Error handling for the number of cmd line arguments (= "ac")
    if (ac != 4)
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }

    // Initialize [filename] [s1] [s2]
    // Declare & Open the file(= av[1]) for reading.
    // Error handling for file(= "infile") opening.
    std::ifstream infile(av[1]);
    if (!infile.is_open())
    {
        std::cout << "File(" << av[1] << ") isn't existed." << std::endl;
        return (1);
    }

    // Initialize 's1' (assign av[2] to 's1').
    // Initialize 's2' (assign av[3] to 's2').
    std::string s1(av[2]);
    std::string s2(av[3]);

    // Error handling for empty arguments (av[1], av[2], av[3]).
    if (std::string(av[1]).empty() || s1.empty() || s2.empty() || !infile.good())
    {
        std::cout << "Command : ./replace [filename] [s1] [s2]" << std::endl;
        return (1);
    }

    // Create the output file with ".replace" appended to the orginal filename.
    // Error handling for file(= "outfile") opening.
    std::ofstream   outfile(std::string(av[1]) + ".replace");
    if (!outfile.is_open())
    {
        std::cout << "Fail to make the outfile" << std::endl;
        return (1);
    }

    // Declare variables for reading the input file content.
    std::string content;
    char    c;

    // Copy characters one by one from the "file" to the "sting".
    // method(get): reads characters from the file (= "infile").
    // method(push_back): adds the character at the end of the string(= "content").
    while (infile.get(c))
        content.push_back(c);

    // Initialize index for the function 'erase_and_insert'.
    // Replace 's1' with 's2' in the content string.
    int i = 0;
    erase_and_insert(&i, &s1, &s2, &content);

    // Write the modified 'content(std::string)' to the 'outfile'.
    outfile << content;

    // close the "infile" & "outfile" (Don't need anymore, must close).
    infile.close();
    outfile.close();
    return (0);
}
