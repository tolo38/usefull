# CI/CD

In software engineering, CI/CD or CICD is the combined practices of continuous integration and continuous delivery or continuous deployment.

Easy to automatize it with git cloud hosting service proviers as [github or gitlab].

Find [Documentation] here and a [Basic Tutorial]

### Gitlab `gitlab-ci.yml`

(my google researches)
- gitlab provide exe for ci
- gitlab ci run executable from repo
- gitlab-ci.yml cd
- ci yml git push
- ci yml set  job order
- gitlab artifacts in readme
- provide artifact as release gitlab


Minimal exemple
```yml
variables:
  NET_LOCATION: //my.server.com/
  NET_INSTALLER_PATH: ${NET_LOCATION}/Installers/${CI_PROJECT_TITLE}/${CI_COMMIT_TAG}/

deploy:
  stage: deploy
  script:
    - msbuild proj.sln /property:Configuration=Release /property:Platform=x64
    - makensis/makensis.exe installer.nsis
    - py -3 $env:_PYTHON\mount_networkfolder.py -s ${NET_LOCATION} --create_folder (${NET_INSTALLER_PATH} -replace '/', '\')
    - xcopy /f /y ('setup.exe' -replace '/', '\') (${NET_INSTALLER_PATH} -replace '/', '\')
  only:
    refs:
      - merge_requests
  artifacts:
    paths:
    - setup.exe
    expire_in: 1 day
```

### Deploy release

- copy file to a server
- Download artifacts
- README [hyperlink to artifact]
- [Release Artifact]



### Push modification 

[Push from CI]

[Push Exemple]

### With Docker

[Tutorial with Docker]


[Basic Tutorial]: https://about.gitlab.com/blog/2020/12/10/basics-of-gitlab-ci-updated/
[Documentation]: https://docs.gitlab.com/ee/ci/yaml/gitlab_ci_yaml.html
[github or gitlab]: https://docs.github.com/en/actions/migrating-to-github-actions/migrating-from-gitlab-cicd-to-github-actions
[hyperlink to artifact]: https://stackoverflow.com/questions/38150090/gitlab-markdown-links-to-artifacts
[Push Exemple]: https://gitlab.com/ixilon/nukkit-docker/blob/master/.gitlab-ci.yml
[Push from CI]: https://forum.gitlab.com/t/git-push-from-inside-a-gitlab-runner/30554
[Release Artifact]: https://crypt.codemancers.com/posts/2021-08-31-release-artifacts-using-gitlab-cicd/
[Tutorial with Docker]: https://www.digitalocean.com/community/tutorials/how-to-set-up-a-continuous-deployment-pipeline-with-gitlab-ci-cd-on-ubuntu-18-04
