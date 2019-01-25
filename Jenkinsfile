pipeline {
  agent {
    dockerfile true
  }
  stages {
    stage("Init title") {
      when { changeRequest() }
      steps {
        script {
          currentBuild.displayName = "PR ${env.CHANGE_ID}: ${env.CHANGE_TITLE}"
        }
      }
    }
    stage('Install dependencies') {
      steps {
        sh '''
          curl https://sh.rustup.rs -sSf | sh -s -- -y
          . $HOME/.cargo/env
          rustup toolchain install 1.28.0
          rustup default 1.28.0
        '''
      }
    }
    stage('Build and Test') {
      steps {
        ansiColor('xterm') {
          sh '''
            ./ciscript
          '''
        }
      }
    }
  }
}
