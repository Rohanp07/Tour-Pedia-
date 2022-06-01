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
          <Route path="/addTour" element={<AddEditTour />} />
          <Route path="/editTour/:id" element={<AddEditTour />} />

        </Routes>

      </div>
    </BrowserRouter>

  );
}

export default App;
