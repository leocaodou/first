import jieba
txt = open("三国演义.txt", "rb").read()
words = jieba.lcut(txt)
counts1 = {}
counts = {}
biaodian =" …《》，、。？！；：“”‘’'\n\r-=—()（）.【】『』"
name = ["曹操","刘备","孔明","张飞","关羽","丞相","赵云","孙权","蜀国","魏国","吕布","荆州","关公"]
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
y1 = 0
while(True):
	word1, count1 = items1[i]
	if(count1 < 100):
		break
	print("{0:<5}{1:>5}".format(word1, count1),end = '  ')
	i = i + 1
	j = 0
	o = 0
	while(True) :
		word2, count2 = items[j]
		if word1 == word2:
			print("{0:<5}{1:>5}".format(word2, count2))
			o = 1
			break
		j = j + 1
		if  j >= len(items) :
			break
	if int(count1) / float(count2) > 3 or float(count1) / float(count2) < 1 :
		y1 = y1 + 1
	if o == 0:
		y1 = y1 + 1
		print("\n",end = '')
y1 = y1/i 
i = 0
y2 = 0
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
	if int(count1) / float(count2) > (3/4) or float(count1) / float(count2) < (1/3) :
		y2 = y2 + 1
	if o == 0:
		y2 = y2 + 1
		print("\n",end = '')
y2 = y2 / i
print("相似率：",((1 - y2)*100 + (1 - y1)*100)/2,'%') 