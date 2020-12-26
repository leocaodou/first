<template>
  <div id="app" align="center">
    <div id="pieReport" style="width: 400px;height: 300px;"></div>
  </div>
</template>

<script>
export default {
  name: "",
  data() {
    return {
      charts: "",
      opinion: ["已完成任务", "未完成任务"],
      opinionData: [
        { value: 12, name: "已完成任务", itemStyle: "#1ab394" },
        { value: 18, name: "未完成任务", itemStyle: "#79d2c0" }
      ]
    };
  },
  methods:{
    drawPie(id) {
          this.charts = this.$echarts.init(document.getElementById(id));
          this.charts.setOption({
            tooltip: {
              trigger: "item",
              formatter: "{a}<br/>{b}:{c} ({d}%)"
            },
            legend: {
              bottom: 10,
              left: "center",
              data: this.opinion
            },
            series: [
              {
                name: "状态",
                type: "pie",
                radius: "65%",
                center: ["50%", "50%"],
                avoidLabelOverlap: false,
                itemStyle: {
                  emphasis: {
                    shadowBlur: 10,
                    shadowOffsetX: 0,
                    shadowColor: "rgba(0, 0, 0, 0.5)"
                  },
                  color: function(params) {
                    //自定义颜色
                    var colorList = ["#00aa7f", "#d25456"];
                    return colorList[params.dataIndex];
                  }
                },
                data: this.opinionData
              }
            ]
          });
        },
  },
  mounted() {
      this.$nextTick(function() {
        this.drawPie("pieReport");
      });
    }

}

</script>

<style scoped>

</style>
