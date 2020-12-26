import Vue from 'vue'
import Vuex from 'vuex'
Vue.use(Vuex)

export default new Vuex.Store({
    state:{
        //任务列表
        list: [
            {name: '学习', describe:'做Vue作业', date1:'2020-12-01', date2:'2020-12-21', region: true,isfinished:1,msg:'好难啊啊啊啊啊啊啊啊啊啊'},
            {name: '生活', describe:'买东西', date1:'2020-12-12', date2:'2020-12-12', region: false , isfinished:3,msg:'买不起啊啊啊啊'},
            {name: '实验', describe:'做计算机网络实验', date1:'2020-12-02', date2:'2020-12-18', region: false , isfinished:3,msg:'做不来啊啊啊啊啊啊啊啊啊'},
            {name: '娱乐', describe:'打游戏', date1:'2020-12-19', date2:'2020-12-20', region: true,isfinished:2,msg:'好好玩啊啊啊啊'},
        ],
        search: ''
    },
    mutations: {
        addItem(state, value){
            console.log(value)
            state.list.unshift(value)
        },
        delItem(state, index){
            state.list.splice(index,1)
        },
        editItem(state, value){
            state.list.splice(value.index,1,value.item)
        },
        search(state,value){
            state.search = value
            console.log(state.search)
        }
    }
})
