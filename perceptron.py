from functools import reduce
class Perceptron(object):
	def __init__(self, input_num, activator):
		self.activator = activator
		self.weights = [0.0 for _ in range(input_num)]
		self.bias= 0.0
	def _str_(self):
		return "weights\t:%s\nbias\t:%f\n" % (self.weights,self.bias)
	def predict(self,input_vec):
		return self.activator(reduce(lambda a, b: a + b,[x * w for x,w in zip(input_vec, self.weights)], 0.0) + self.bias)
	def train(self, input_vec, labels, iteration, rate):
		for i in range(iteration):
			self._one_iteration(input_vec, labels, rate)

	def _one_iteration(self, input_vec, labels ,rate):
		samples = zip(input_vec, labels)
		for(input_vec, labels) in samples:
			output = self.predict(input_vec)
			self._update_weights(input_vec, output, labels,rate)
	def _update_weights(self, input_vec, output ,labels, rate):
		delta = labels - output
		self.weights = [w + rate * delta * x for x,w in zip(input_vec, self.weights)]
		self.bias += rate * delta
def f(x):
	return 1 if x > 0 else 0
def get_training_dataset():
	input_vec =[[1,1], [0,0], [1,0], [0,1]]
	labels = [1,0,0,0]
	return input_vec, labels

def train_and_perceptron():
	p = Perceptron(2,f)
	input_vec, labels = get_training_dataset()
	p.train(input_vec, labels, 10, 0.1)
	return p

if __name__ == '__main__':
	and_perception = train_and_perceptron()
	print (and_perception._str_())
	print ('1 and 1 = %d' % and_perception.predict([1, 1]))
	print ('0 and 0 = %d' % and_perception.predict([0, 0]))
	print ('1 and 0 = %d' % and_perception.predict([1, 0]))
	print ('0 and 1 = %d' % and_perception.predict([0, 1]))