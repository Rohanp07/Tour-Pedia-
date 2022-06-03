import React, { useEffect } from "react";
import './App.css';
import { ToastContainer } from 'react-toastify';
import "react-toastify/dist/ReactToastify.css";

import { BrowserRouter, Routes, Route } from "react-router-dom";
import Login from "./Pages/Login";
import Register from "./Pages/Register";
import Home from "./Pages/Home";
import Header from "./components/Header";

//persist of user
import { useDispatch } from 'react-redux';
import { setUser } from "./redux/features/authSlice";
import AddEditTour from "./Pages/AddEditTour";
import SingleTour from "./Pages/SingleTour";
import Dashboard from "./Pages/Dashboard";
import PrivateRoute from "./components/PrivateRoute";



function App() {
  const dispatch = useDispatch();
  const user = JSON.parse(localStorage.getItem('profile'));

  useEffect(() => {
    dispatch(setUser(user));

  }, []);
  return (
    <BrowserRouter>
      <div className="App">
        <Header />
        <ToastContainer />
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/login" element={<Login />} />
          <Route path="/register" element={<Register />} />
          <Route
            path="/addTour"
            element={
              <PrivateRoute>
                <AddEditTour />
              </PrivateRoute>
            }
          />
          <Route
            path="/editTour/:id"
            element={
              <PrivateRoute>
                <AddEditTour />
              </PrivateRoute>}
          />
          <Route
            path="/tour/:id"
            element={
              <PrivateRoute>
                <SingleTour />
              </PrivateRoute>

            }
          />
          <Route
            path="/dashboard"
            element={
              <PrivateRoute>
                <Dashboard />
              </PrivateRoute>
            }
          />
        </Routes>

      </div>
    </BrowserRouter>

  );
}

export default App;
