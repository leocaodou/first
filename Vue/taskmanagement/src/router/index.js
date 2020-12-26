import Vue from 'vue';
import Router from 'vue-router';
import List from '@/components/list.vue';
import Title from '@/components/title.vue';
import Menu from '@/components/menu.vue';
import Task from '@/components/task.vue';
import Calendar from '@/components/calendar.vue';
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      redirect: '/menu'
    },

    {
      path: '/menu',
      name: 'menu',
      redirect: '/menu/task',
      component: Menu,
      children: [
        {
          path: 'task',
          name: 'task',
          redirect: '/menu/task/list',
          component: Task,
          children:[
            {
              path: 'list',
              name: 'list',
              component: List,
            },
            {
              path: 'calendar',
              name: 'calendar',
              component: Calendar,
            }
          ]
        },
        {
          path: 'title',
          name: 'title',
          component: Title
        }
      ]
    }
  ]
})
