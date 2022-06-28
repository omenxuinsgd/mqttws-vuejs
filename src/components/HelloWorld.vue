<script setup>
defineProps({
  msg: {
    type: String,
    required: true
  }
})
</script>

<template>
  <div class="greetings">
    <h1 class="green">{{ msg }}</h1>
    <h3 style="text-align: justify; font-size: medium; font-weight: 600px; line-height: 20px;">
      Sistem tertanam dan IoT adalah Matakuliah Pilihan bagi mahasiswa yang sudah mengambil
      Konsentrasi di Jurusan Teknik Elektro UIN Bandung.
      <router-link to="/stiot" style="text-decoration: none;">Selengkapnya...</router-link>
    </h3>
  </div>
</template>

<style scoped>
h1 {
  font-weight: 500;
  font-size: 2rem;
  top: -10px;
}

h3 {
  font-size: 1.2rem;
  font-weight: normal;
}

a{
  text-decoration: none;
}

.greetings h1,
.greetings h3 {
  text-align: center;
}

@media (min-width: 1024px) {
  .greetings h1,
  .greetings h3 {
    display: block;
    text-align: left;
  }
}
</style>
