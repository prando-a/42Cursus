/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-12 10:50:36 by prando-a          #+#    #+#             */
/*   Updated: 2024-06-12 10:50:36 by prando-a         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ftSed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        return (std::cout << "Error: Wrong args count\n", 1);
    try
    {
        ftSed sed(argv[1]);
        sed.ftReplace(argv[2], argv[3]);
    }
    catch (std::exception &e) 
       { return (std::cout << e.what(), 1); }
    return (0);
}