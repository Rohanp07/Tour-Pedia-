import React, { useState } from "react";

import {
    MDBNavbar,
    MDBContainer,
    MDBIcon,
    MDBNavbarNav,
    MDBNavbarItem,
    MDBNavbarLink,
    MDBNavbarToggler,
    MDBCollapse,
    MDBNavbarBrand
}
    from "mdb-react-ui-kit";

import { useSelector, useDispatch } from "react-redux";
import { setLogout } from "../redux/features/authSlice";
import { searchTours } from "../redux/features/tourSlice";
import { useNavigate } from "react-router-dom";

const Header = () => {

    const [show, setShow] = useState(false);
    const { user } = useSelector((state) => ({ ...state.auth }));
    const [search, setSearch] = useState("");

    const navigate = useNavigate();

    const dispatch = useDispatch();


    if (token) {
        const decodedToken = decode(token);

        if (decodedToken.exp * 1000 < new Date().getTime()) {
            dispatch(setLogout());
        }
    }

    const handleSubmit = (e) => {
        e.preventDefault();
        console.log("search is ", search);
        if (search) {
            dispatch(searchTours(search));
            navigate(`/tour/search?searchQuery=${search}`);
            setSearch("");
        } else {
            navigate("/");
        }
    }

    const handleLogout = () => {
        dispatch(setLogout());
    }
    return (
        <MDBNavbar fixed="top" expand="lg" style={{ backgroundColor: "#f0e6ea" }}>
            <MDBContainer>
                <MDBNavbarBrand
                    href="/"
                    style={{ color: "#606080", fontWeight: "600", fontSize: "22px" }}
                >
                    Touropedia
                </MDBNavbarBrand>
                <MDBNavbarToggler
                    type="button"
                    aria-expanded="false"
                    aria-label="Toogle navigation"
                    onClick={() => setShow(!show)}
                    style={{ color: "#606080" }}
                >
                    <MDBIcon icon="bars" fas />
                </MDBNavbarToggler>
                <MDBCollapse show={show} navbar>
                    <MDBNavbarNav right fullWidth={false} className="mb-2 mb-lg-0">
                        {(user && user.result && user.result._id) && (
                            <h5 style={{ marginRight: "30px", marginTop: "27px" }}>
                                Logged in as: {user.result.name}
                            </h5>
                        )}
                        <MDBNavbarItem>
                            <MDBNavbarLink href="/">
                                <p className="header-text">Home</p>
                            </MDBNavbarLink>
                        </MDBNavbarItem>
                        {(user && user.result && user.result._id) && (
                            <>
                                <MDBNavbarItem>
                                    <MDBNavbarLink href="/addTour">
                                        <p className="header-text">Add Tour</p>
                                    </MDBNavbarLink>
                                </MDBNavbarItem>
                                <MDBNavbarItem>
                                    <MDBNavbarLink href="/dashboard">
                                        <p className="header-text">Dashboard</p>
                                    </MDBNavbarLink>
                                </MDBNavbarItem>
                            </>
                        )}
                        {(user && user.result && user.result._id) ? (
                            <MDBNavbarItem>
                                <MDBNavbarLink href="/login">
                                    <p className="header-text" onClick={() => handleLogout()}>
                                        Logout
                                    </p>
                                </MDBNavbarLink>
                            </MDBNavbarItem>
                        ) : (
                            <MDBNavbarItem>
                                <MDBNavbarLink href="/login">
                                    <p className="header-text">Login</p>
                                </MDBNavbarLink>
                            </MDBNavbarItem>
                        )}
                    </MDBNavbarNav>
                    <form className="d-flex input-group w-auto" onSubmit={handleSubmit} >
                        <input
                            type="text"
                            className="form-control"
                            placeholder="Search Tour"
                            value={search}
                            onChange={(e) => setSearch(e.target.value)}
                        />
                        <div style={{ marginTop: "5px", marginLeft: "5px" }}>
                            <MDBIcon fas icon="search" />
                        </div>
                    </form>
                </MDBCollapse>
            </MDBContainer>
        </MDBNavbar>
    )
}

export default Header;