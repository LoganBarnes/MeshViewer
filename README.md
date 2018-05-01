Mesh Viewer
===========

Check out
```bash
$ git clone https://github.com/LoganBarnes/MeshViewer.git
$ cd MeshViewer
```

Create virtual environment for python
```bash
$ virtualenv -p python3 venv
$ . venv/bin/activate
```

Install pymesh module and run test scripts
```bash
(venv) $ pip install -e . -v
(venv) $ ./scripts/server.py &
(venv) $ ./scripts/client.py
(venv) $ ./scripts/client.py
(venv) $ ./scripts/client.py
```

All together now.
```bash
git clone https://github.com/LoganBarnes/MeshViewer.git
cd MeshViewer
virtualenv -p python3 venv
. venv/bin/activate
pip install -e . -v
./scripts/server.py &
./scripts/client.py
./scripts/client.py
./scripts/client.py

```
