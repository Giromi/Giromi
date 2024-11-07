/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsuki2 <minsuki2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:18:36 by minsuki2          #+#    #+#             */
/*   Updated: 2023/01/23 18:24:35 by minsuki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	showElement(T& em) {
	std::cout << em << std::endl;
}

// void	showElement(int em) {
// 	std::cout << em << std::endl;
// }
//
// void	showElement(double em) {
// 	std::cout << em << std::endl;
// }

// template <typename T>
// void	showElement(T& em) {
// 	std::cout << em << std::endl;
// }

// Q. 왜 <int>를 붙여야 하는가?
//
template <typename T1, typename T2>
void	iter(T1* arr, int len, T2 func) {
	for (int i = 0; i < len; ++i) {
		func(arr[i]);
	}
}

/* ---------------------------------------------------------- */

// Q. 왜 아래와 같이 2개를 만들어야 하는가?
// A. const T& 와 T& 는 다른 타입이기 때문에, 함수 오버로딩이 필요하다.
// Q. 왜 T& 만 있으면 Compile 에러가 나는가?
// A. const T& 는 T& 를 받을 수 있지만, T& 는 const T& 를 받을 수 없기 때문이다.
//

// template <typename T1, typename T2>
// void iter(const T1* arr, int len, void (*f)(const T2&)) {
//     std::cout << "const T&" << std::endl;
//     for (int i = 0; i < len; ++i) {
//         f(arr[i]);
//     }
// }


// 얘만 있으면 Compile 에러
// Q. 왜 const 를 빼면 안되는가?
// template <typename T>
// void iter(T* arr, int len, void (*f)(T&)) {
//     std::cout << "T&" << std::endl;
//     for (int i = 0; i < len; ++i) {
//         f(arr[i]);
//     }
// }


# define RESET   "\0330m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#endif
