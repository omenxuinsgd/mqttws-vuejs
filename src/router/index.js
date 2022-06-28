import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'

Vue.use(VueRouter)

const router = new VueRouter({
  mode: 'history',
  base: import.meta.env.BASE_URL,
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView
    },
    {
      path: '/about',
      name: 'about',
      // route level code-splitting
      // this generates a separate chunk (About.[hash].js) for this route
      // which is lazy-loaded when the route is visited.
      component: () => import('../views/AboutView.vue')
    },
    {
      path: '/documentation',
      name: 'docs',
      component: () => import('../views/Docs.vue')
    },
    {
      path: '/dhtlogger',
      name: 'dhtlogger',
      component: () => import('../views/DhtLogger.vue')
    },
    {
      path: '/stiot',
      name: 'stiot',
      component: () => import('../views/Stiot.vue')
    },
    {
      path: '/demo',
      name: 'demo',
      component: () => import('../views/Demo.vue')
    },
  ]
})

export default router
