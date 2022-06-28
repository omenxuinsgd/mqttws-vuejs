<template>
  <div class="about" style="margin-top: 20px;">
        <div class="row container d-flex justify-content-center">
          <div class="col-xl-12 col-md-12">
            <div class="card user-card-full">
              <div class="row m-l-0 m-r-0">
                <div class="col-sm-12 bg-c-lite-greens user-profile">
                  <div class="card-block text-center text-white">
                    <div class="m-b-25">
                      <img src="https://img.icons8.com/bubbles/100/000000/user.png" class="img-radius"
                        alt="User-Profile-Image">
                    </div>
                    <h6 class="f-w-600" style="font-size: 22px; color: green;">Sistem Tertanam & IoT</h6>
                    <p style="color: green;">Pembimbing: Edi Mulyana, M.T.</p>
                    <p class="text-muted f-w-400" style="text-align: justify; font-size: smaller; text-indent: 20px; line-height: 18px;">
                      Sistem tertanam dan IoT adalah Matakuliah Pilihan bagi mahasiswa yang sudah mengambil Konsentrasi di Jurusan Teknik Elektro UIN Bandung.

                    </p>
                    <i class=" mdi mdi-square-edit-outline feather icon-edit m-t-10 f-16"></i>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
</template>

<style>
.padding {
  padding: 3rem !important;
  min-width: 100%;
}

.user-card-full {
  overflow: hidden;
  min-width: 100%;
}

.card {
  min-width: 100%;
  border-radius: 5px;
  -webkit-box-shadow: 0 1px 20px 0 rgba(69, 90, 100, 0.08);
  box-shadow: 0 1px 20px 0 rgba(69, 90, 100, 0.08);
  border: none;
  margin-bottom: 30px;
}

.m-r-0 {
  margin-right: 0px;
}

.m-l-0 {
  margin-left: 0px;
}

.user-card-full .user-profile {
  border-radius: 5px 0 0 5px;
}

.bg-c-lite-greens {
  /* background: -webkit-gradient(linear, left top, right top, from(#f29263), to(#ee5a6f)); */
  background: linear-gradient(to top, white, aqua);
}

.user-profile {
  padding: 20px 0;
}

.card-block {
  padding: 1.25rem;
}

.m-b-25 {
  margin-bottom: 25px;
}

.img-radius {
  border-radius: 5px;
}



h6 {
  font-size: 14px;
}

.card .card-block p {
  line-height: 25px;
}

@media only screen and (min-width: 1400px) {
  p {
    font-size: 14px;
  }
}

.card-block {
  padding: 1.25rem;
}

.b-b-default {
  border-bottom: 1px solid #e0e0e0;
}

.m-b-20 {
  margin-bottom: 20px;
}

.p-b-5 {
  padding-bottom: 5px !important;
}

.card .card-block p {
  line-height: 25px;
}

.m-b-10 {
  margin-bottom: 10px;
}

.text-muted {
  color: #919aa3 !important;
}

.b-b-default {
  border-bottom: 1px solid #e0e0e0;
}

.f-w-600 {
  font-weight: 600;
}

.m-b-20 {
  margin-bottom: 20px;
}

.m-t-40 {
  margin-top: 20px;
}

.p-b-5 {
  padding-bottom: 5px !important;
}

.m-b-10 {
  margin-bottom: 10px;
}

.m-t-40 {
  margin-top: 20px;
}

.user-card-full .social-link li {
  display: inline-block;
}

.user-card-full .social-link li a {
  font-size: 20px;
  margin: 0 10px 0 0;
  -webkit-transition: all 0.3s ease-in-out;
  transition: all 0.3s ease-in-out;
}



@media (min-width: 1024px) {
  .about {
    min-width: 100%;
    min-height: 100vh;
    display: flex;
    align-items: center;
  }
}
</style>
