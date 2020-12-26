<template>
  <router-view></router-view>
</template>

<script>
export default {
      handleSelect(key, keyPath) {
        console.log(key, keyPath);
      }
  }
</script>

<style>
</style>
