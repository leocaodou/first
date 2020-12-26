<template>
  <el-container>
    <el-header>
      <span>
        <h1>任务管理系统</h1>
      </span>
    </el-header>
    <el-container>
      <el-aside width="200px">
        <el-menu
          :default-active="title"
          class="el-menu-vertical-demo"
          :router="true"
          >
          <div @click="log()">
            <el-avatar v-if="!islogin" icon="el-icon-user-solid" :size="70" style="margin-bottom: -50px;"/>
            <el-avatar v-else src="https://cube.elemecdn.com/0/88/03b0d39583f48206768a7534e55bcpng.png" :size="70" style="margin-bottom: -50px;"/>
          </div>
          <el-menu-item index="/menu/task/list">
            <i class="el-icon-menu"></i>
              <span slot="title">我的任务</span>
          </el-menu-item>
          <el-menu-item index="/menu/title">
            <i class="el-icon-s-data"></i>
              <span slot="title">统计</span>
          </el-menu-item>
        </el-menu>
      </el-aside>
      <el-main>
        <h1 v-if="!islogin">请登录后再使用</h1>
        <router-view v-else></router-view>
        <el-dialog
          title="欢迎使用任务管理系统"
          :visible.sync="logindia"
          width="30%"
          center>
          <el-form ref="ruleform" :model="ruleForm" label-width="80px" :rules="rules">
            <el-form-item label="用户名" prop="username">
              <el-input v-model="username"></el-input>
            </el-form-item>
            <el-form-item label="密码" prop="password">
              <el-input v-model="password" type="password"></el-input>
            </el-form-item>
            <el-form-item>
              <el-button @click="logindia = false">取 消</el-button>
              <el-button type="primary" @click="loging">确 定</el-button>
            </el-form-item>
          </el-form>
        </el-dialog>
      </el-main>
    </el-container>
  </el-container>
</template>
<script>
  export default {
    data(){
      return {
        dialogVisible: false,
        islogin:false,
        logindia:false,
        username:'',
        password:'',
        rules: {
          username: [
            { required: true, message: '请填写用户名', trigger: 'blur' },
          ],
          password: [
            { required: true, message: '请填写密码', trigger: 'blur' }
          ],
        }
      };
    },
    methods:{
      log(){
        this.logindia=true;
      },
      loging(){
        if(this.username != '' && this.password != '')
        {
          this.logindia = false;
          this.islogin=true;
        }
        console.log("test",this.username);
        console.log("test",this.password);
      }
    }
    }
</script>

<style>
  .el-header{
      background-color: #ffffff;
      color: #16a9f5;
      line-height: 20px;
      box-shadow: 0 2px 4px rgba(0, 0, 0, .12), 0 0 6px rgba(0, 0, 0, .04) ;
      margin-bottom: 10px;
      text-align: left;
    }
    .el-aside {
      background-color: #ffffff;
      color: #333;
      text-align: center;
      line-height: 120px;
      box-shadow: 0 2px 4px rgba(0, 0, 0, .12), 0 0 6px rgba(0, 0, 0, .04) ;
      height: 600px;
    }

    .el-main {
      background-color: #E9EEF3;
      color: #333;
      text-align: center;
      line-height: 0px;
      box-shadow: 0 2px 4px rgba(0, 0, 0, .12), 0 0 6px rgba(0, 0, 0, .04) ;
      height: 600px;
    }

    body > .el-container {
      margin-bottom: 40px;
    }

    .el-container:nth-child(5) .el-aside,
    .el-container:nth-child(6) .el-aside {
      line-height: 260px;
    }

    .el-container:nth-child(7) .el-aside {
      line-height: 320px;
    }
</style>
