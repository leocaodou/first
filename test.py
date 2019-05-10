import jieba
txt = open("hlm_utf_8.txt", "r", encoding='utf-8').read()
words = jieba.lcut(txt)
counts1 = {}
counts = {}
biaodian =" …《》，、。？！；：“”‘’'\n\r-=—()（）.【】『』"
name = ["宝玉","凤姐","贾母","王夫人","薛姨妈","贾琏","宝钗","黛玉","林黛玉","贾宝玉","老太太","湘云","刘姥姥","薛蟠",""]
for word in words:
	if word in biaodian:
		word = '#'
	if len(word) == 1 or word in name :
		continue
	if word == "第八十一回":
		break;
	counts1[word] = counts1.get(word, 0) + 1
items1 = list(counts1.items())
items1.sort(key=lambda x: x[1], reverse=True)
x = 0
for word in words:
	if word == "第八十一回":
		x = 1
	if x == 1:
		if word in biaodian:
			word = '#'
		if len(word) == 1 or word in name:
			continue
		counts[word] = counts.get(word, 0) + 1
print("前八十回       后四十回")
items = list(counts.items())
items.sort(key=lambda x: x[1], reverse=True)
i = 0
j = 0
o = 0
y1 = 0
a = [0] * 100
b = [0] * 100
while(True):
	word1, count1 = items1[i]
	for word in words :
		if '第' and '回' in word:
			if word == "第八十一回" :
				break;
			j = j + 1
			continue
		if word == word1 :
			a[j] = a[j] + 1
	sum1=0.0
	sum2=0.0
	for k in range(1,81):
		sum1+=a[k]
		sum2+=a[k]**2
	mean=sum1/80
	var=sum2/80-mean**2
	b[i] = var
	i = i + 1
	if i > 80 :
		break
y1 = y1 / i
i = 0
y2 = 0
o = 0
print("\n\n\n")
while(True):
	word1, count1 = items[i]
	if(count1 < 50):
		break
	print("{0:<5}{1:>5}".format(word1, count1),end = '  ')
	i = i + 1
	j = 0
	o = 0
	while(True) :
		word2, count2 = items1[j]
		if word1 == word2:
			print("{0:<5}{1:>5}".format(word2, count2))
			o = 1
			break
		j = j + 1
		if  j >= len(items) :
			break
	y2 = (1/(float(count1) / float(count2)) - 2)**2 + y2
	if o == 0:
		print("\n",end = '')
y2 = y2 /i
print(y1,y2)
print("相似率：",((1 - y2)*100 + (1 - y1)*100)/2,end = '%') 