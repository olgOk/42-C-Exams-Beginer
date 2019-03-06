/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 18:28:51 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/05 18:29:06 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
---------------------------------------------------
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index, followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.
Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		letter;

	i = 0;
	while (argc ==2 && argv[1][i])
	{
		letter = 0;
		if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
            letter = argv[1][i] - 'A' + 1;
		else if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
			letter = argv[1][i] - 'a' + 1;
        else
            write(1, &argv[1][i], 1);
        while (letter--)
            write (1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}