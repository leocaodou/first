<template>
  <div>
    <el-table :data="list" style="width: 100%"  >
      <el-table-column prop="name" label="类型" width="150px" align="center"> </el-table-column>
      <el-table-column prop="describe" label="任务详情"  width="400" align="left"> </el-table-column>
      <el-table-column prop="date1" label="开始日期" sortable  width="200"> </el-table-column>
      <el-table-column prop="date2" label="截止日期" sortable  width="200"> </el-table-column>
      <el-table-column prop="region" label="标记" sortable width="160">
        <template slot-scope="scope" >
          <div @click="mark(scope.$index)">
            <el-button v-if="list[scope.$index].region" icon="el-icon-star-off" type="primary" circle></el-button>
            <el-button v-else icon="el-icon-star-on" circle></el-button>
          </div>
         </template>
      </el-table-column>
      <el-table-column prop="isfinished" label="完成情况" sortable width="130">
        <template slot-scope="scope">
          <el-tag v-if="scope.row.isfinished==1" effect="dark">未开始</el-tag>
          <el-tag v-else-if="scope.row.isfinished==2" type="success" effect="dark">已完成</el-tag>
          <el-tag v-else type="danger" effect="dark">未完成</el-tag>
        </template>
      </el-table-column>
       <el-table-column align="left">
         <template slot = "header" slot-scope="scope">
           <el-row :gutter="20">
                 <el-col :span="19">
                     <el-input placeholder="请输入要搜索的任务" v-model="$store.state.search">
                         <i slot="prefix" class="el-input__icon el-icon-search"></i>
                     </el-input>
                 </el-col>
                 <el-col :span="1" >
                   <el-button type="primary" icon="el-icon-plus" @click="addFormVisible = true" circle></el-button>
                 </el-col>
           </el-row>
         </template>
         <template slot-scope="scope">
          <el-button type="primary" @click="look(scope.$index)">查看</el-button>
         </template>
      </el-table-column>
    </el-table>
    <el-drawer
      title="查看项目"
      :visible.sync="drawer"
      :direction="direction"
      :before-close="handleClose"
      align="center">
      <h1 style="font-size: 40px;">{{showForm.describe}}</h1>
      <el-tag>{{showForm.name}}</el-tag>
      <el-tag v-if="showForm.isfinished==1" effect="dark">未开始</el-tag>
      <el-tag v-else-if="showForm.isfinished==2" type="success" effect="dark">已完成</el-tag>
      <el-tag v-else type="danger" effect="dark">未完成</el-tag>
      <el-divider content-position="center">时间</el-divider>
      <el-avatar icon="el-icon-date"></el-avatar>
      <div style="margin-top: 10px;">
        <span style="color: #409EFF;">起:{{showForm.date1}}&nbsp;&nbsp;</span>
        <span style="color: #FF0000;">止:{{showForm.date2}}</span>
      </div>
      <el-divider >备注</el-divider>
      <div style="height: 400px;">
        <span style="font-size: 20px;">{{showForm.msg}}</span>
      </div>
      <el-button style="font-size: 30px;" @click="modFormVisible = true" round>修改</el-button>
      <el-button style="font-size: 30px;" type="danger" @click="handleClose2" round>删除</el-button>
    </el-drawer>



    <el-dialog title="新建任务" :visible.sync="addFormVisible">
      <el-form :model="form">
        <el-form-item label="类型" >
          <el-input v-model="addForm.name" autocomplete="off"></el-input>
        </el-form-item>
        <el-form-item label="任务详情">
          <el-input v-model="addForm.describe" autocomplete="off"></el-input>
        </el-form-item>
        <el-form-item label="开始日期" >
          <el-date-picker
                v-model="addForm.date1"
                align="right"
                type="date"
                placeholder="选择开始日期"
                value-format="yyyy-MM-dd"
                :picker-options="pickerOptions">
           </el-date-picker>
        </el-form-item>
        <el-form-item label="截止日期" >
          <el-date-picker
                v-model="addForm.date2"
                align="right"
                type="date"
                placeholder="选择开始日期"
                value-format="yyyy-MM-dd"
                :picker-options="pickerOptions">
           </el-date-picker>
        </el-form-item>
        <el-form-item label="备注" >
          <el-input
            type="textarea"
            autosize
            placeholder="请输入备注"
            v-model="addForm.msg">
          </el-input>
        </el-form-item>
      </el-form>
      <div slot="footer" class="dialog-footer">
        <el-button @click="addFormVisible = false">取 消</el-button>
        <el-button type="primary" @click="add">确 定</el-button>
      </div>
    </el-dialog>

    <el-dialog title="修改任务" :visible.sync="modFormVisible">
      <el-form :model="form">
        <el-form-item label="类型" >
          <el-input v-model="showForm.name" autocomplete="off"></el-input>
        </el-form-item>
        <el-form-item label="任务详情">
          <el-input v-model="showForm.describe" autocomplete="off"></el-input>
        </el-form-item>
        <el-form-item label="开始日期" >
          <el-date-picker
                v-model="showForm.date1"
                align="right"
                type="date"
                placeholder="选择开始日期"
                value-format="yyyy-MM-dd"
                :picker-options="pickerOptions">
           </el-date-picker>
        </el-form-item>
        <el-form-item label="截止日期" >
          <el-date-picker
                v-model="showForm.date2"
                align="right"
                type="date"
                placeholder="选择开始日期"
                value-format="yyyy-MM-dd"
                :picker-options="pickerOptions">
           </el-date-picker>
        </el-form-item>
        <el-form-item label="备注" >
          <el-input
            type="textarea"
            autosize
            placeholder="请输入备注"
            v-model="showForm.msg">
          </el-input>
        </el-form-item>
      </el-form>
      <div slot="footer" class="dialog-footer">
        <el-button @click="modFormVisible = false">取 消</el-button>
        <el-button type="primary" @click="mod">确 定</el-button>
      </div>
    </el-dialog>
  </div>


</template>

<script>
export default {
  name: 'List',
  data(){
    return{
      dialogVisible:false,
      addFlag:false,
      drawer: false,
      addFormVisible: false,
      modFormVisible: false,
      formLabelWidth: '50px',
      direction: 'rtl',
      showForm:{
          index:'',
          name: '',
          describe:'',
          date1:'',
          date2:'',
          region: '',
          isfinished:'',
          msg:''
      },
      addForm:{
          name: '',
          describe:'',
          date1:'',
          date2:'',
          region: '',
          isfinished:'',
          msg:''
      },
      pickerOptions: {
                shortcuts: [{
                  text: '今天',
                  onClick(picker) {
                    picker.$emit('pick', new Date());
                  }
                }, {
                  text: '昨天',
                  onClick(picker) {
                    const date = new Date();
                    date.setTime(date.getTime() - 3600 * 1000 * 24);
                    picker.$emit('pick', date);
                  }
                }, {
                  text: '一周前',
                  onClick(picker) {
                    const date = new Date();
                    date.setTime(date.getTime() - 3600 * 1000 * 24 * 7);
                    picker.$emit('pick', date);
                  }
                }]
              },
    };
  },
  methods: {
        handleOpen(key, keyPath) {
          console.log(key, keyPath);
        },
        handleClose(key, keyPath) {
          console.log(key, keyPath);
        },
        mark(index){
          this.list[index].region = !this.list[index].region;
          console.log("test",index);
        },
        handleClose(done) {
                this.$confirm('确认关闭？')
                  .then(_ => {
                    done();
                  })
                  .catch(_ => {});
        },
        look(index){
          this.drawer=true;
          this.showForm.index = index;
          this.showForm.name = this.list[index].name;
          this.showForm.describe = this.list[index].describe;
          this.showForm.date1 = this.list[index].date1;
          this.showForm.date2 = this.list[index].date2;
          this.showForm.region = this.list[index].region;
          this.showForm.isfinished = this.list[index].isfinished;
          this.showForm.msg = this.list[index].msg;
        },
        handleClose2(){
          this.$confirm('确认删除？')
            .then(_ => {
              console.log("test","关闭");
              this.drawer=false;
              this.$store.commit('delItem',this.showForm.index);
              this.$notify({
               message: "任务删除成功",
               type: "success"
               });

            })
            .catch(_ => {});
        },
        add(){
          this.addFormVisible = false;
          this.addForm.region = false;
          if(Date.parse(this.addForm.date1) <= new Date())
            this.addForm.isfinished=3;
          else
            this.addForm.isfinished=1;
          this.$store.commit('addItem',this.addForm);
          this.$notify({
              message: '任务创建成功',
              type: 'success'
          });
          this.addForm={brand_right:0}
        },
        mod(){
          var index = this.showForm.index;
          this.list[index].name= this.showForm.name;
          this.list[index].describe = this.showForm.describe;
          this.list[index].date1 = this.showForm.date1;
          this.list[index].date2 = this.showForm.date2;
          this.list[index].region = this.showForm.region;
          this.list[index].isfinished = this.showForm.isfinished;
          this.list[index].msg = this.showForm.msg;
          this.modFormVisible = false;
        }
      },
  computed: {
    list(){ //模糊查询，过滤
      return this.$store.state.list.filter(data =>
        !(this.$store.state.search) ||
        data.name.toLowerCase().includes(this.$store.state.search.toLowerCase()) ||
        data.describe.toLowerCase().includes(this.$store.state.search.toLowerCase()) ||
        data.date1.includes(this.$store.state.search) ||
        data.date2.includes(this.$store.state.search) ||
        data.region==this.$store.state.search ||
        data.progress==this.$store.state.search
      )
    },
  },
}
</script>

<style scoped>

</style>
