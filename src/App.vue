<script setup>
import HelloWorld from '@/components/HelloWorld.vue'
import SupportIcon from '@/components/icons/IconSupport.vue'
</script>

<template>
  <div id="app">
    <header>
      <img alt="Vue logo" class="logo" src="@/assets/uinsgd-logo.png" width="150" height="180" />

      <div class="wrapper">
        <HelloWorld msg="Sistem Tertanam & IoT" />

        <nav style="text-decoration: none;">
          <router-link to="/" style="text-decoration: none;">Home</router-link>
          <router-link to="/documentation" style="text-decoration: none;">Docs</router-link>
          <router-link to="/demo" style="text-decoration: none;">Demo</router-link>
          <router-link to="/about" style="text-decoration: none;">About</router-link>
        </nav>
        <div style="position: absolute; bottom: 290px; left: -160px;">
         <p>Dibuat dengan <SupportIcon style="color: red;"/> oleh <span class="green">Nur Rokhman, Kurnia Sandi & Dini Amelia</span></p>
         <p style="position: relative; bottom: 20px;">Berterimakasih kepada Bapak<span class="green" style="margin-top: 0;"> Edi Mulyana, M.T.</span> selaku dosen pengampu</p>
        </div>
      </div>
    </header>

    <router-view />
  </div>
</template>

<script>
import TheWelcome from '@/components/TheWelcome.vue'
export default {
  components: {
    TheWelcome
  },
  mounted () {
    this.$mqtt.subscribe('stiot/umeng/#')
  }
}
</script>

<style>
@import '@/assets/base.css';

#app {
  max-width: 1280px;
  margin: 0 auto;
  padding: 2rem;

  font-weight: normal;
}

header {
  line-height: 1.5;
  max-height: 100vh;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

a,
.green {
  text-decoration: none;
  color: hsla(160, 100%, 37%, 1);
  transition: 0.4s;
}

@media (hover: hover) {
  a:hover {
    background-color: hsla(160, 100%, 37%, 0.2);
  }
}

nav {
  width: 100%;
  font-size: 12px;
  text-align: center;
  margin-top: 2rem;
}

nav a.router-link-exact-active {
  color: var(--color-text);
}

nav a.router-link-exact-active:hover {
  background-color: transparent;
}

nav a {
  display: inline-block;
  padding: 0 1rem;
  border-left: 1px solid var(--color-border);
}

nav a:first-of-type {
  border: 0;
}

@media (min-width: 1024px) {
  body {
    display: flex;
    place-items: center;
  }

  #app {
    display: grid;
    grid-template-columns: 1fr 1fr;
    padding: 0 2rem;
  }

  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  nav {
    text-align: left;
    margin-left: -1rem;
    font-size: 1rem;

    padding: 1rem 0;
    margin-top: 1rem;
  }
}
</style>
