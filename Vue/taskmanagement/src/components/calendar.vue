<template>
    <el-calendar>
      <!-- 这里使用的是 2.5 slot 语法，对于新项目请使用 2.6 slot 语法-->
      <template
        slot="dateCell"
        slot-scope="{date, data}">
        <p >
          {{ data.day }}
          <div style="font-size: 25px;">
            <el-popover
                placement="top-start"
                title="任务"
                width="200"
                trigger="hover"
                content="有任务没有完成">
              <i v-if="has(data.day)" class="el-icon-warning-outline" slot="reference"></i>
            </el-popover>
          </div>
        </p>
      </template>
    </el-calendar>
</template>

<script>
  export default {
    name: 'Calender',
    data(){
      return{
        isCollapse:true,
        visible: false,
      };
    },
    methods: {
      has(date){
          var cur = this.$store.state.list.filter(data =>
          data.date1 <= date &&
          date <= data.date2 &&
          data.isfinished != 2
          );
          if(cur != '')
            return true;
          else
            return false;
      }
    },
  }
</script>

<style>
  .is-selected {
      color: #1989FA;
    }
</style>
