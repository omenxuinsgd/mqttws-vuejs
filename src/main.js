import Vue from 'vue'
import VueCompositionAPI, { createApp, h } from '@vue/composition-api'

import App from './App.vue'
import router from './router'

import 'bootstrap/dist/css/bootstrap.min.css'
import 'bootstrap/dist/js/bootstrap.min'

import VueMqtt from 'vue-mqtt'

import VueApexCharts from 'vue-apexcharts/dist/vue-apexcharts';
import LazyTube from "vue-lazytube";

Vue.use(LazyTube);
Vue.component('apexchart', VueApexCharts)

Vue.use(VueCompositionAPI)

Vue.use(VueMqtt, "ws://test.mosquitto.org:8080", {clientId: 'WebClient-' + parseInt(Math.random() * 100000)})
Vue.config.productionTip = false

const app = createApp({
  router,
  render: () => h(App)
})

app.mount('#app')
