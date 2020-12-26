import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.NullWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;


public class SecondaryReducer extends Reducer<Text, IntWritable, NullWritable, Text> {

	public void reduce(Text _key, Iterable<Text> values, Context context)
			throws IOException, InterruptedException {
		// process values
		for (Text val : values) {
			context.write(NullWritable.get(), val);
		}
	}

}
