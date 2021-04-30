# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarbie <abarbie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 13:14:12 by abarbie           #+#    #+#              #
#    Updated: 2021/03/16 01:50:54 by abarbie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import os

def generate_args(size):
	args = []
	i = 0
	while i < size:
		arg = random.randint(-10000, 10000)
		if arg not in args:
			args.append(arg)
			i += 1
	return ' '.join([str(arg) for arg in args])

def get_cmd(arg):
	return "ARG=\"" + arg + "\"; ./push_swap $ARG | ./checker $ARG > tmp; ./push_swap $ARG | wc -l >> tmp"

def test_loop(arg_number, tolerance, tests = 1000):
	max_res = 0
	for i in range(tests):
		args = generate_args(arg_number)
		os.system(get_cmd(args))
		out = open('tmp', 'r').read().split()
		os.remove('tmp')
		try:
			if int(out[1]) > max_res:
				max_res = int(out[1])
			if out[0] != 'OK':
				print("KO FOUND. Arguments: ", args)
			elif int(out[1]) > tolerance:
				print("TOLERANCE EXCESS FOUND (", out[1], " > ", tolerance, ")")
		except:
			print("Exception: ", out)
	print("TEST", arg_number, "OVER. Max moves:", max_res)

if __name__ == "__main__":
	test_loop(1, 0, 1000)		# max moves: 0
	test_loop(2, 1, 1000)		# max moves: 1
	test_loop(3, 3, 5000)		# max moves: 2
	test_loop(4, 12, 3000)		# max moves: 9
	test_loop(5, 12, 2000)		# max moves: 11
	test_loop(6, 700, 1000)		# max moves: 18
	test_loop(10, 700, 1000)	# max moves: 37
	test_loop(50, 700, 1000)	# max moves: 283
	test_loop(100, 700, 1000)	# max moves: 674
	test_loop(500, 5500, 50)	# max moves: 4894
	test_loop(1000, 100000, 1)	# max moves: 11530
