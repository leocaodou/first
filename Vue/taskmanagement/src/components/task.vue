<template>
  <div>
    <el-radio-group v-model="isList" style="margin-bottom: 20px;" :change="choose(isList)">
      <el-radio-button :label="true" >列表</el-radio-button>
      <el-radio-button :label="false" >日历</el-radio-button>
    </el-radio-group>
    <router-view></router-view>
  </div>
</template>

<script>
export default {
  name: 'Task',
  data(){
    return{
      isList:true,
    };
  },
  methods: {
    choose(index){
      if(index)
        this.$router.push("list",onComplete => {},onAbort => {});
      else
        this.$router.push("calendar",onComplete => {},onAbort => {});
    }
  }
}
</script>

<style scoped>

</style>
