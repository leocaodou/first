def calcu_sub_str_num(mom_str,sun_str):
	count = 0
	for i in range(len(mom_str)-1):
		if mom_str[i:i+len(sun_str)] == sun_str:
			count+=1
	return count
mom_str = "lll"
sun_str = input()
print('%d'%calcu_sub_str_num(mom_str,sun_str))