pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'g++ arbitrage.cpp -o arbitage'
      }
    }
    stage('Test') {
      steps {
        sh 'date'
      }
    }
  }
}