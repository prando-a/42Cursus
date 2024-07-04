/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:50:47 by prando-a          #+#    #+#             */
/*   Updated: 2024/07/01 17:50:47 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEUTILS_HPP
# define BASEUTILS_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif